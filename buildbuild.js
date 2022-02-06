function run(cm){
	Deno.writeTextFileSync('build.sh',`emcc main.cpp -O3 -o webtest/em.html -s EXPORTED_FUNCTIONS='["_runCode","${cm.join('","')}"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'`)
}
let{log}=console
let std=Deno.readTextFileSync("std.cpp")
std=std.match(/void \$.+\(\)/g).map(e=>'_'+e.slice(5,-2))
run(std)