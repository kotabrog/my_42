/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time-server.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:43:50 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/29 01:00:46 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const net = require('net');

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

function now_date() {
	const date = new Date();
	error_exit(isNaN(date), "date object could not be created successfully.");
	const yyyy = String(date.getFullYear());
	const MM = String(date.getMonth() + 1).padStart(2, "0");
	const dd = String(date.getDate()).padStart(2, "0");
	const hh = String(date.getHours()).padStart(2, "0");
	const mm = String(date.getMinutes()).padStart(2, "0");

	return `${yyyy}-${MM}-${dd} ${hh}:${mm}`;
}

error_exit((process.argv.length < 3), "No arguments");
try
{
	var server = net.createServer(function (socket) {
		try
		{
			socket.end(now_date() + '\n');
		}
		catch (err)
		{
			socket.end('error');
		}
	})
	server.listen(parseInt(process.argv[2]));
	server.on("error", function(err) {
		console.log(err.message);
	});
}
catch (err)
{
	console.log(err.message);
}
