public class MapboxJNI {
    static {
        System.loadLibrary("mapbjava");
    }

    private native void render(String url, MapboxCallback callback);
    
    public static void main(String[] args) {
        new MapboxJNI().render("http://nourl.com", new MapboxCallback("hello from java"));
    }
}
