import mapboxswift

let url = "http://nourl.com"
let pointer = UnsafeMutablePointer(mutating: Array(url.utf8CString))
mapboxswift.render(pointer, {
    print("Hello from Swift")
})

