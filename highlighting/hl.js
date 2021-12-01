Rainbow.extend("stonk", [
	{
		name: 'word',
		matches: {
			1:'blockname',
			3: {
				language: "stonkblock"
			},
			7:'variable'
		},
		pattern: /(@[^\n ]+)(\n| )((([^;&]|&(gt|lt|amp);)*))(;)/gs
	}
])
Rainbow.extend("stonkblock", [
	{
		name:'text',
		pattern:/('|\.)[^ ]*/g,
		matches:[{
			name: 'number',
			pattern: /'\d+/g
		}]
	},
	{
		name:'operator',
		pattern:/[+\-*\/%]([a-zA-Z])\b|[=|{}]/g,
		matches:{
			1:'type'
		}
	},
	{
		name:'variable',
		pattern:/(\$|\-&gt;)[^ ]+/g,
		matches:{
			1:'operator'
		}
	}
])
Rainbow.color()
let sh = document.createElement("style")
sh.innerHTML = `
.blockname{
	color:#B267E6
}
.block{
	color:#fff
}
.number{
	color:#b5cea8
}
.text{
	color:#ce9178
}
.operator{
	color:#fff
}
.type{
	color:#4ec9b0;
}
.variable{
	color:#9cdcfe
}
.word{
	color:#569cd6
}
`

document.body.appendChild(sh)