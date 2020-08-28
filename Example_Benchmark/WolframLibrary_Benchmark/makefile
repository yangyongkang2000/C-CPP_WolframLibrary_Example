name = WolframLibrary_Benchmark
$(name).so : $(name).c
		gcc -shared -fPIC -O3 $(name).c -o $(name).so
.PHONY : clean
clean :
		rm $(name).so