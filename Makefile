BinStree:Bin_ser_tree.o
	gcc $^ -o $@
%.c:%.o
	gcc -c $^
.PHONY:clean
clean:
	rm *.o BinStree
