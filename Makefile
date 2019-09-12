docker-build:
	docker build . -t ev3dev:v1

shell:
	docker run -e EV3_APP_NAME=og3 -v $(shell pwd):/gateway -it ev3dev:v1 sh

run:
	docker run -d -e EV3_APP_NAME=og3 -v $(shell pwd):/gateway -it ev3dev:v1

# TODO: v1に依存しないように修正
save:
	docker save ev3dev:v1 ev3dev_v1.tar
	zip ev3dev_v1.tar.zip ev3dev_v1.tar
	rm -rf ev3dev_v1.tar
