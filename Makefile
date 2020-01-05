CONTENA_NAME := ro2020/ev3dev:v1
RELEASE_DIR_NAME := releases

init: __vol __docker-build
	@echo " __        _______ _     ____ ___  __  __ _____   _____ ___  \n \ \      / / ____| |   / ___/ _ \|  \/  | ____| |_   _/ _ \ \n  \ \ /\ / /|  _| | |  | |  | | | | |\/| |  _|     | || | | |\n   \ V  V / | |___| |__| |__| |_| | |  | | |___    | || |_| |\n    \_/\_/  |_____|_____\____\___/|_|  |_|_____|   |_| \___/ \n"
	@echo " ______   ___   _     _ ___ _______     _______   ____  _______     __\n|  _ \ \ / / | | |   | |_ _| ____\ \   / /___ /  |  _ \| ____\ \   / /\n| |_) \ V /| | | |_  | || ||  _|  \ \ / /  |_ \  | | | |  _|  \ \ / / \n|  _ < | | | |_| | |_| || || |___  \ V /  ___) | | |_| | |___  \ V /  \n|_| \_\|_|  \___/ \___/|___|_____|  \_/  |____/  |____/|_____|  \_/   \n"

__docker-build:
	@docker build -t $(CONTENA_NAME) --rm=true ./docker

build:
ifdef APP_NAME
	@docker run -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=$(APP_NAME) -v $(shell pwd):/myhost $(CONTENA_NAME)
else
	@docker run -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/myhost $(CONTENA_NAME)
endif
test:
	@g++ -std=c++11 test.cpp -pthread -lgtest -lgtest_main
	@$(shell pwd)/a.out
sh:
ifeq  ($(shell uname),Darwin)
	@docker run -it --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/host $(CONTENA_NAME) sh
else
	@winpty docker run -it --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/host $(CONTENA_NAME) sh
endif

branch/deleteAll:
	@git branch | grep -v 'develop\|master\|gh-pages' | grep -v '*' | xargs git branch -D

__vol:
	@mkdir -p $(RELEASE_DIR_NAME)
