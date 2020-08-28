name = Inversions
name2 = Naive_InverseNumber
all : $(name) $(name2)
.PHONY : all
$(name2).so :  $(name2).cpp
		g++ -shared -fPIC -O3 $(name2).c -o $(name2).so
$(name).so : $(name).cpp
		g++ -shared -fPIC -O3 $(name).c -o $(name).so
.PHONY : clean
clean :
		rm $(name).so