SET( INCS
../../include/Ernaehrung.h
../../include/Zutat.h
../../include/Lebensmittel.h
../../include/Gericht.h
../../include/Menue.h
)


SET( SRCS
../../src/Ernaehrung.cpp
../../src/Lebensmittel.cpp
../../src/Gericht.cpp
../../src/main.cpp
)


ADD_EXECUTABLE( MAIN
	${INCS}
	${SRCS}
)

