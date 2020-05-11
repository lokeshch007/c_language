TARGET	=	main
CSRC	=	$(TARGET).c	#c sources variable 
CSRC	+=	#list of all .c files added to c sources variable
COBJ	=	$(CSRC:.c=.o)	#all .c files are reused as .o files
CC		=	gcc	#compiler variable assigned with gcc compiler
OPT		=	2	#optimisation variable assigned with optimisation level 2
DEBUG	=	-ggdb3	#debugger variable assigned with -ggdb3 debugger	
CFLAGS	=	-Wall $(DEBUG) -O$(OPT)	#compiler flags variable warnings all,debugger,optimisation level
LDFLAGS	=	#linker flags of LD linker(no flags)

all:$(TARGET)	#all is command line argument for make file
$(TARGET):$(COBJ)
			$(CC) -o $@  $^  $(CFLAGS)  $(LDFLAGS)

$(COBJ):%.o:%.c
		  $(CC) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) $(COBJ)

.PHONY:clean all

