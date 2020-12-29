/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asyncio.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:09:46 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/29 11:35:32 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length <= 2)
	console.log("No arguments");
else
{
	const fs = require("fs");
	const file_path = process.argv[2];
	fs.readFile(file_path, { encoding: "utf8" }, (err, file) => {
		if (err)
		{
			console.log("The file could not be read");
		}
		else
		{
			let sum = 0;
			for (let i = 0; i < file.length; ++i)
				if (file[i] == '\n')
					++sum;
			console.log(sum);
		}
	});
}
