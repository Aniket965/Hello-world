PACKAGES:=$(shell go list ./... | sed -n '1!p' | grep -v /vendor/)

default: run

run:
	go run main.go

depends:
	glide up

test:
	echo "mode: count" > coverage-all.out
	touch coverage.out
	$(foreach pkg,$(PACKAGES), \
		go test -p=1 -cover -covermode=count -coverprofile=coverage.out ${pkg}; \
		tail -n +2 coverage.out >> coverage-all.out;)
	rm coverage.out

