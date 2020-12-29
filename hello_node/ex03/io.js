/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.js                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:53:37 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/28 15:36:31 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length <= 2)
	console.log("No arguments");
else
{
	const fs = require("fs");
	const file_path = process.argv[2];
	try
	{
		const file = fs.readFileSync(file_path, 'utf8');
		let sum = 0;
		for (let i = 0; i < file.length; ++i)
			if (file[i] == '\n')
				++sum;
		console.log(sum);
	}
	catch (err)
	{
		console.log("The file could not be read");
	}
}
