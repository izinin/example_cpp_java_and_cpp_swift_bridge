# mapbox_gl_native
this is test assignment for job application in Mapbox

## API change

* the problem with current API it is **stateful** - we access the same memory allocation on subsequent API invocations. This approach is doable by passing a binary buffer through IPC. Then we need a special API call to clean that memory and do not forget to call it every time. Expect awful user experience and bugs about memory leaking.
* memory allocation for `StyledMap` should happen on client side to allow the client managing memory
* there are two options in the API modification:
  1. having `StyledMap` broken down by `StyledMap` properties in JNI function call, for example in `StyledMap` currently only a single property `url` then we could have API call `render(String url, VoidFunction* callback)`. We can extend properties easily without breaking the API backward compatibility. This is the most preferable approach in our case. However if there are more than 10 properties, it makes sense
  1. allocate `StyledMap` on client side and pass it to JNI function call, for example there is java class StyledMap which is passed to JNI function with signature `render(StyledMap* style, VoidFunction* callback)`

## JAVA binding
### setup developer environment on Ubuntu

**Note** [zulu java JDK distribution](https://www.azul.com/) is used. in case of some other JDK use please update environment variable JAVA_INC accordingly
```bash
apt-get update
apt-get -y install cmake build-essential
cd /tmp
wget https://cdn.azul.com/zulu/bin/zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb
apt -y install ./zulu11.56.19-ca-jdk11.0.15-linux_amd64.deb
```

### build shared libraries
```bash
export JAVA_INC=/usr/lib/jvm/zulu-11-amd64/include
cmake --configure .
cmake --build .
```

### run java binding example

```bash
cd binding/java
javac MapboxJNI.java
java -Djava.library.path=. MapboxJNI
```

## SWIFT binding
### setup developer environment on Ubuntu
```bash
apt-get -y install \
          binutils \
          git \
          gnupg2 \
          libc6-dev \
          libcurl4 \
          libedit2 \
          libgcc-9-dev \
          libpython2.7 \
          libsqlite3-0 \
          libstdc++-9-dev \
          libxml2 \
          libz3-dev \
          pkg-config \
          tzdata \
          uuid-dev \
          zlib1g-dev
cd /tmp
wget https://download.swift.org/swift-5.6.1-release/ubuntu2004/swift-5.6.1-RELEASE/swift-5.6.1-RELEASE-ubuntu20.04.tar.gz
tar xzf swift-5.6.1-RELEASE-ubuntu20.04.tar.gz
mv swift-5.6.1-RELEASE-ubuntu20.04 /usr/share/swift
echo "export PATH=/usr/share/swift/usr/bin:$PATH" >> ~/.bashrc
source ~/.bashrc
```
### run example
```
cd binding/swift
swift run
```

### References
* It looks like [dynamic loading library API](https://forums.swift.org/t/swift-dynamic-loading-api/39495) is not implemented in swift 
* it is possible to use swift [dynamic libraries made with package manager](https://theswiftdev.com/building-and-loading-dynamic-libraries-at-runtime-in-swift/)
