public class MapboxCallback {
    private String prompt;

    public MapboxCallback(String prompt){
        this.prompt = prompt;
    }

    public void callback() {
        System.out.println(prompt);
    }
}