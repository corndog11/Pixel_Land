socialmake:
	 main.cpp
	g++ -static main.cpp tui.h tui.cpp account.h account.cpp database.cpp database.h -o social -lmysqlcppconn -lmysqlclient -lz -ldl -pthread
