# mapbox_gl_native
this is test assignment for job application in Mapbox

## API change

* the problem with current API it is **stateful** - we access the same memory allocation on subsequent API invocations. This approach is doable by passing a binary buffer through IPC. Then we need a special API call to clean that memory and do not forget to call it every time. Expect awful user experience and bugs about memory leaking.
* memory allocation for `StyledMap` should happen on client side to allow the client managing memory
* there are two options in the API modification:
  1. having `StyledMap` broken down by `StyledMap` properties in JNI function call, for example in `StyledMap` currently only a single property `url` then we could have API call `render(String url, VoidFunction* callback)`. We can extend properties easily without breaking the API backward compatibility. This is the most preferable approach in our case. However if there are more than 10 properties, it makes sense
  1. allocate `StyledMap` on client side and pass it to JNI function call, for example there is java class StyledMap which is passed to JNI function with signature `render(StyledMap* style, VoidFunction* callback)`

## setup devloper environment on Ubuntu

**Note** [zulu java JDK distribution](https://www.azul.com/) is used. in case of some other JDK use please update environment variable JAVA_INC accordingly
```bash
apt-get update
apt-get -y install cmake build-essential
cd /tmp
wget https://cdn.azul.com/zulu/bin/zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb
apt -y install ./zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb
```

## build shared libraries
```bash
export JAVA_INC=/usr/lib/jvm/zulu-11-amd64/include
cmake --configure .
cmake --build .
```

## run java binding example

```bash
cd binding/java
javac MapboxJNI.java
java -Djava.library.path=. MapboxJNI
```
