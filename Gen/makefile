gen.exe:	book.o editorial.o header_book.o header_editorial.o main.o
	g++ -std=c++11 book.o editorial.o header_book.o header_editorial.o	main.o

book.o: book.cpp book.hpp
	g++ -std=c++11 -c book.cpp

editorial.o: editorial.cpp editorial.hpp
	g++ -std=c++11 -c editorial.cpp

header_editorial.o:	header_editorial.hpp header_editorial.cpp editorial.hpp
	g++ -std=c++11 -c header_editorial.cpp

header_book.o:	header_book.hpp header_book.cpp book.hpp
	g++ -std=c++11 -c header_book.cpp

main.o:	main.cpp editorial.hpp book.hpp header_book.hpp header_editorial.hpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o *.out