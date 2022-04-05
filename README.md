Install from here
https://emscripten.org/docs/getting_started/downloads.html
https://www.jamesfmackenzie.com/2019/12/01/webassembly-graphics-with-sdl/

set up dev env. 

https://web.archive.org/web/20220223003055/https://giovanni.codes/setup-sdl2-with-visual-studio-code-and-mingw64-on-windows/

emcc -c sdl_2_0_sample.c -o sdl_2_0_sample.o -s USE_SDL=2
emcc sdl_2_0_sample.o -o sdl_2_0_sample.html -s USE_SDL=2

 python3 -m http.server
Remember to never block inside the loop function - doing so will prevent your app from drawing to the screen. Also you can only have one Emscripten loop running - no nesting!\

void emscripten_set_main_loop(em_callback_func func, int fps, int simulate_infinite_loop)

source:
https://www.jamesfmackenzie.com/2019/12/01/webassembly-graphics-with-sdl/