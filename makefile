socialmake:
	 g++ -I mysql main.cpp tui.h tui.cpp account.h image.h image.cpp account.cpp database.cpp database.h -o social -LSDL -lSDL2 -lSDL2_image -Lmysql -lmysqlcppconn -lmysqlclient
