Rainbow.extend("stonk", [
	{
		name: 'word',
		matches: {
			1: 'blockname',
			3: {
				language: "stonkblock"
			},
			7: 'variable'
		},
		pattern: /(@[^\n ]+)(\n| )((([^;&]|&(gt|lt|amp);)*))(;)/gs
	}
])
Rainbow.extend("stonkblock", [
	{
		name: 'text',
		pattern: /(^| )('|\.)[^ ]*/g,
		matches: [{
			name: 'number',
			pattern: /'\d+/g
		}]
	},
	{
		name: 'operator',
		pattern: /(^| )[+\-*\/%]([a-zA-Z]{1,2})\b|[=|]\b|[\{\}]/g,
		matches: {
			2: 'type'
		}
	},
	{
		name: 'variable',
		pattern: /(^| )(\$|\-&gt;)[^ ]+\b/g,
		matches: {
			1: 'operator'
		}
	},
	{
		name:'comment',
		pattern: /(^| )\( .* \)\b/g
	}
])
let update = () => {
	Rainbow.color(text.value, 'stonk', e => {
		code.innerHTML = e
	})
}
update()
text.oninput = update
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
.comment{
	color:#6a9955
}
`

document.body.appendChild(sh)