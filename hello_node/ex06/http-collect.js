/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-collect.js                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:06:27 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/28 15:59:14 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var http = require('http')
var bl = require('bl')

if (process.argv.length < 3)
{
	console.log("No arguments");
	process.exit(-1);
}
try
{
	req = http.get(process.argv[2], function(res) {
		res.pipe(bl(function (err, data) {
			if (err)
			{
				console.log(err.message);
				process.exit(-1);
			}
			data = data.toString();
			console.log(data.length);
			console.log(data);
		}));
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
