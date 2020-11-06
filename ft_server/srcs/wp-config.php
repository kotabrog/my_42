<?php
define( 'DB_NAME', 'wp' );
define( 'DB_USER', 'wordpress' );
define( 'DB_PASSWORD', 'password' );
define( 'DB_HOST', 'localhost' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

define('AUTH_KEY',         'dQ~UL2X7b?gI(CeQp8r$Mp~J)twx|,-$;00_$X;Sn Da{5#BQZ:` V6!OJX-L.ZR');
define('SECURE_AUTH_KEY',  '@(_|1?RsFKyFm(,YNK%t{A&nML4+FF-l>OF{|dX9gw;&XNVZ*1C_rOaCVUpli+0-');
define('LOGGED_IN_KEY',    '(kIygLa;YYu&O|gw-]J`(l.|J=![x1F_BK}n2FONqCF1c}._B81{8kf6X-nn7}uu');
define('NONCE_KEY',        '76o+rT$NsDfE/8Hi-;Yhc)rr`Jg01C{Z4?9B0v`12pDu+fY(JaZWZ*t8/0v|>Udo');
define('AUTH_SALT',        ' %kh=_+AA)X/|L]NNbkS8,{hN]JVsn_u_Ga5W[]ToZr`hw3m+OoXSs^1%;1@;]4h');
define('SECURE_AUTH_SALT', 'p/ g}AqX|Yu)O8T]`F$4LK+~sP>F2FdV>e6Yb^GgQVbiim<9sw2@z3uG?`D||S`O');
define('LOGGED_IN_SALT',   'Z3#@@+=%2[{r^E1_r&jD-0k<3TJ`@d .i<EZ{C9+K>HGz75_co|h{wSa=N+p-mfn');
define('NONCE_SALT',       'Z g!89@-CU)i]>C,k!1nWoCdt[W%71-Q*mCT?]/*F2D{/19`0O}n&_|C@]/xXLu-');

$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once(ABSPATH . 'wp-settings.php');
