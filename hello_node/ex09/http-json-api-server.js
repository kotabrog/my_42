/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-json-api-server.js                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:28:43 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/29 00:59:33 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const http = require('http');

function error_exit(err, str)
{
	if (err)
	{
		if (str)
			console.log(str);
		else
			console.log(err.message);
		process.exit(-1);
	}
}

function parse_date(time)
{
	try
	{
		const parse1 = time.split('T');
		const parse2 = parse1[0].split('-');
		const parse3 = parse1[1].split(':');
		const parse4 = parse3[2].split('.');
		let date = new Date();
		date.setUTCMilliseconds(parseInt(parse4[1]));
		date.setUTCSeconds(parse4[0]);
		date.setUTCMinutes(parse3[1]);
		date.setUTCHours(parse3[0]);
		date.setUTCDate(parse2[2]);
		date.setUTCMonth(parse2[1] - 1);
		date.setUTCFullYear(parse2[0]);
		return (date);
	}
	catch (err)
	{
		return (NaN);
	}
}

error_exit((process.argv.length < 3), "No arguments");
try
{
	var server = http.createServer(function (request, response) {
		try
		{
			const uri = request.url.split('?');
			if (uri[0] === '/api/parsetime' || uri[0] === '/api/unixtime')
			{
				const iso = uri[1].split('=');
				let obj;
				if (iso[0] === 'iso')
				{
					const date = parse_date(iso[1]);
					if (isNaN(date))
						response.end("error\n");
					if (uri[0] === '/api/parsetime')
						obj = {hour: date.getUTCHours(), 
									minute: date.getUTCMinutes(), 
									second: date.getUTCSeconds()};
					else
						obj = {unixtime: date.getTime()};
				}
				response.end(JSON.stringify(obj) + '\n');
			}
			response.end("error\n");
		}
		catch (err)
		{
			response.end("error\n");
		}
	}).listen(parseInt(process.argv[2]));
	server.on("error", function(err) {
		console.log(err.message);
	});
}
catch (err)
{
	console.log(err.message);
}
