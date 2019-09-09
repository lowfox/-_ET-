CONTENA_NAME := ro2020/ev3dev:v1
VOLUME_DIR_NAME := releases

dk/build:
	docker build -t $(CONTENA_NAME) --rm=true .

dk/run:
ifdef APP_NAME
	docker run -it --rm -e VOLUME_DIR_NAME=$(VOLUME_DIR_NAME) -e APP_NAME=$(APP_NAME) -v $(shell pwd)/$(VOLUME_DIR_NAME):/$(VOLUME_DIR_NAME) $(CONTENA_NAME)
else
	docker run -it --rm -e VOLUME_DIR_NAME=$(VOLUME_DIR_NAME) -e APP_NAME=app -v $(shell pwd)/$(VOLUME_DIR_NAME):/$(VOLUME_DIR_NAME) $(CONTENA_NAME)
endif

dk/brun: dk/build dk/run

dk/sh:
	docker run -it --rm -e VOLUME_DIR_NAME=$(VOLUME_DIR_NAME) -e APP_NAME=app -v $(shell pwd)/$(VOLUME_DIR_NAME):/$(VOLUME_DIR_NAME) $(CONTENA_NAME) sh

init: __vol
	echo 'we will win, you know?'

__vol:
	mkdir $(VOLUME_DIR_NAME)
