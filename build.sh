emcc main.cpp -O3 -o webtest/em.html -s EXPORTED_FUNCTIONS='["_runCode","_$pop","_$dup","_$square","_$if","_$swap","_$repeat","_$times","_$stob","_$btos","_$mod","_$nth","_$del","_$strlength","_$addb","_$subb","_$stack","_$stacknth","_$gets","_$prints","_$run","_$stacklen"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'