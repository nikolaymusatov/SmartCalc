OS := $(shell uname -s)
ifeq ($(OS), Linux)
    D_ENV=__LINUX__
    OPEN_GCOV= xdg-open Test/coverage/coverage.html
else
    D_ENV=__MAC_OS__
    OPEN_GCOV= open Test/coverage/coverage.html
endif

all: install test gcov_report

install:
	@mkdir build
	-cd build && qmake ../SmartCalc.pro -o makefile_f
	-cd build && make install -f makefile_f
	@cd build && rm -rf *.o *.cpp *.h makefile_f .qmake.stash

uninstall:
	@rm -rf build

dvi:
	@doxygen ./Resourses/doxyfile
	@open ./doc/html/index.html

dist: install
	@cd build && tar -cf SmartCalc_v2.0.tar SmartCalc.app && cp SmartCalc_v2.0.tar ../
	@rm -rf build

clean:
	@rm -rf Test/build
	@rm -rf Test/coverage
	@rm -rf *.tar
	@rm -rf doc
	@rm -rf *.css
	@rm -rf *.html

test:
	@cd Test && mkdir build
	@cd Test/build && qmake ../Test.pro -o makefile_f
	@cd Test/build && make Test -f makefile_f
	@cd Test/build && rm -rf *.o *.cpp *.h makefile_f .qmake.stash
	@cd Test/build && ./Test

gcov_report:
	@cd Test && mkdir coverage
	@cd Test/coverage && gcovr -r ../.. --html-details=coverage.html
	@$(OPEN_GCOV)

.PHONY: all clean uninstall install dvi dist test gcov_report