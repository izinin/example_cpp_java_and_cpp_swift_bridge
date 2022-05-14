# mapbox_gl_native
this is test assignment for job application in Mapbox

## API change

* the problem with current API it is **stateful**
* we access the same memory allocation on subsequent API invocations. This approach is doable by passing a binary buffer through inter process communication (IPC). Then we need a special API call to clean that memory and do not forget to call it every time. Expect awful user experience and bugs about memory leaking.
* memory allocation for `StyledMap` should happen on client side to allow the client managing memory
* there are two options in the API modification:
  1. having `StyledMap` broken down by `StyledMap` properties in JNI function call, for example in `StyledMap` currently only a single property `url` then we could have API call `render(String url)`. We can extend properties easily without breaking the API backward compatibility. This is the most preferable approach in our case. However if there are more than 10 properties, it makes sense
  1. allocate `StyledMap` on client side and pass it to JNI function call, for example there is java class StyledMap which is passed to JNI function with signature `render(StyledMap* style, VoidFunction* callback)`

## setup devloper environment on Ubuntu

with root user permission:
```
apt-get update
apt-get -y install cmake build-essential
cd /tmp
wget https://cdn.azul.com/zulu/bin/zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb
apt -y install ./zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb

```

## build
```
cmake --build .
```

## run
```
./mapbox_gl_native
```