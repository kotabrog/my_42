/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   async-http-collect.js                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:35:23 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/28 19:23:51 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


var http = require('http');
var holder = [];
var path_list = [];
const arg_count = 3;

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

function output_in_order(obj)
{
	return new Promise(function(resolve) {
		try
		{
			req = http.get(obj.path, function(res){
				res.setEncoding('utf8');
				var string = '';
				res.on('data', function(chunk){
					string += chunk;
				});
				res.on('end', function(){
					holder[obj.count] = string;
					resolve(res);
				});
			}).setTimeout(5000).on('timeout', function() {
				console.log('request timed out');
				req.abort();
			}).on('error', function(err) {
				console.log(err.message);
			});
		}
		catch (err)
		{
			error_exit(err);
			process.exit(-1);
		}
	});
}

async function put_all(path_list)
{
	const promises = path_list.map(function(path) {
		return output_in_order(path);
	});
	const res = await Promise.all(promises);
	for (let i = 0; i < arg_count; ++i)
		console.log(holder[i]);
}

error_exit((process.argv.length < arg_count + 2), "No arguments");
for (let i = 0; i < arg_count; ++i)
	path_list.push({
		"path": process.argv[2 + i],
		"count": i
	});
put_all(path_list);
