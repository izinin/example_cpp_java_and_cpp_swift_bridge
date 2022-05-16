// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "mapboxswift",
    products: [
        .executable(name: "example", targets: ["example"]),
        .library(
            name: "mapboxswift",
            // type: .static,
            targets: ["mapboxswift"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .executableTarget(
            name: "example",
            dependencies: [
                "mapboxswift"
            ]
        ),
        .target(
            name: "mapboxswift",
            dependencies: [],
            cxxSettings: [.unsafeFlags(["-std=c++17"])]
        )
    ]
)
