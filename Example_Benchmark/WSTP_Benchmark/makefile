name_1 = WSTP_PutInteger
name_2 = WSTP_PutIntegerList
EXTERN = -lWSTP64i4 -lm -lpthread -lrt -lstdc++ -ldl -luuid
all : $(name_1) $(name_2)
.PHONY : all
$(name_1) : $(name_1).c
		gcc -O3 $(name_1).c $(EXTERN) -o $(name_1)
$(name_2) : $(name_2).c
		gcc -O3 $(name_2).c $(EXTERN) -o $(name_2)
$(name_1).c : $(name_1).tm
		wsprep $(name_1).tm  -o $(name_1).c
$(name_2).c : $(name_2).tm
		wsprep $(name_2).tm  -o $(name_2).c
.PHONY : clean
clean  :        
		rm $(name_1) $(name_2)