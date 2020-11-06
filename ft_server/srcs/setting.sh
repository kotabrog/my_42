cp /tmp/srcs/default.conf /etc/nginx/sites-available/default
if test "${AUTOINDEX}" = "off"; then
	sed -i -e "s/autoindex on;/autoindex off;/" /etc/nginx/sites-available/default
fi

mkdir /etc/nginx/ssl
cd /etc/nginx/ssl
openssl genrsa -out server.key
openssl req -new -key server.key -out server.csr -subj '/C=JP/ST=Tokyo/L=Tokyo/O=ksuzuki/OU=Web/CN=localhost'
openssl x509 -in server.csr -days 3650 -req -signkey server.key > server.crt

service mysql start
mysql -u root < /tmp/srcs/set-mysql

curl https://ja.wordpress.org/latest-ja.tar.gz > /tmp/srcs/latest-ja.tar.gz
tar -xzf /tmp/srcs/latest-ja.tar.gz -C /var/www/html/
cp /tmp/srcs/wp-config.php /var/www/html/wordpress/

curl https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz > /tmp/srcs/phpmyadmin.tar.gz
tar -xzf /tmp/srcs/phpmyadmin.tar.gz -C /var/www/html/
mv /var/www/html/phpMyAdmin* /var/www/html/phpmyadmin

rm -rf /temp/srcs

service nginx start
service php7.3-fpm start
