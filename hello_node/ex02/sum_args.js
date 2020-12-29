/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_args.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 10:56:12 by ksuzuki           #+#    #+#             */
/*   Updated: 2020/12/27 12:33:33 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

let sum = 0;

for (let i = 2; i < process.argv.length; ++i)
	sum += parseInt(process.argv[i]);
if (process.argv.length <= 2)
	console.log("No arguments");
else if (sum != sum)
	console.log("Some items could not be converted to numbers.");
else
	console.log(sum);
