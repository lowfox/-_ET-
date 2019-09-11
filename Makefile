CONTENA_NAME := ro2020/ev3dev:v1
RELEASE_DIR_NAME := releases

dk/build:
	docker build -t $(CONTENA_NAME) --rm=true .

dk/run:
ifdef APP_NAME
	docker run --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=$(APP_NAME) -v $(shell pwd):/host $(CONTENA_NAME)
else
	docker run --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/host $(CONTENA_NAME)
endif

dk/brun: dk/build dk/run

dk/sh:
ifeq  ($(shell uname),Darwin)
	docker run -it --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/host $(CONTENA_NAME) sh
else
	winpty docker run -it --rm -e RELEASE_DIR_NAME=$(RELEASE_DIR_NAME) -e APP_NAME=app -v $(shell pwd):/host $(CONTENA_NAME) sh
endif

init: __vol
	echo 'we will win, you know?'

__vol:
	mkdir $(RELEASE_DIR_NAME)
