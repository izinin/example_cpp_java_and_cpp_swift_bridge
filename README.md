# This is example bridging C++ to java and swift for my educational purposes

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
cd binding/mapboxswift
swift run
```

# General comments
**TODO**: map C++ sources are duplicated for java and swift because swift package manager requires certain directory structure. I could re-layout the project to make 'mapgl' folder shared between two build systems : CMake and Swift SPM not sure how good is to put symbolic links to 'mapgl' folder under source control. Symbolic link shall be created dynamically in a build pipeline i think.
