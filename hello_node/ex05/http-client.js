/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-client.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:26:22 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/28 15:32:12 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var http = require('http');
if (process.argv.length < 3)
{
	console.log("No arguments");
	process.exit(-1);
}
var url = process.argv[2]
try
{
	req = http.get(url, function(res) {
		res.setEncoding('utf8');
		res.on('data', function(chunk) {
			console.log(chunk);
		});
	});
	req.setTimeout(5000).on('timeout', function() {
		console.log('request timed out');
		req.abort();
	});
	req.on("error", function(err) {
		console.log(err.message);
	});
}
catch (err)
{
	console.log(err.message);
}
