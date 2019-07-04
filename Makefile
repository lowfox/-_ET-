docker-build:
	docker build . -t ev3dev:v1

shell:
	docker run -e EV3_APP_NAME=og3 -e TZ=Asia/Tokyo -v $(pwd):/gateway -it ev3dev:v1 sh

run:
	docker run -d -e EV3_APP_NAME=og3 -v $(pwd):/gateway -it ev3dev:v1
