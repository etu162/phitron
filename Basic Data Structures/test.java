// These are some of the classes of a complex 3rd-party video conversion framework.
// We don't control this code, so we can't simplify it.

class VideoFile {
    private String filename;
    private String format;

    public VideoFile(String filename) {
        this.filename = filename;
        this.format = filename.substring(filename.lastIndexOf(".") + 1);
    }

    public String getFilename() {
        return filename;
    }

    public String getFormat() {
        return format;
    }
}

interface Codec {
    String getType();
}

class OggCompressionCodec implements Codec {
    public String getType() {
        return "ogg";
    }
}

class MPEG4CompressionCodec implements Codec {
    public String getType() {
        return "mp4";
    }
}

class CodecFactory {
    public static Codec extract(VideoFile file) {
        System.out.println("CodecFactory: Extracting codec from file: " + file.getFilename());
        return file.getFormat().equals("mp4") ? new MPEG4CompressionCodec() : new OggCompressionCodec();
    }
}

class BitrateReader {
    public static String read(String filename, Codec codec) {
        System.out.println("BitrateReader: Reading file - " + filename + " with codec - " + codec.getType());
        return "RAW_VIDEO_DATA";
    }

    public static String convert(String buffer, Codec codec) {
        System.out.println("BitrateReader: Converting to format - " + codec.getType());
        return "CONVERTED_VIDEO_DATA";
    }
}

class AudioMixer {
    public String fix(String result) {
        System.out.println("AudioMixer: Fixing audio...");
        return result + " (Audio Fixed)";
    }
}

// We create a Facade class to hide the framework's complexity behind a simple interface.
class VideoConverter {
    public File convert(String filename, String format) {
        System.out.println("\n=== Video Conversion Started ===");
        VideoFile file = new VideoFile(filename);
        Codec sourceCodec = CodecFactory.extract(file);
        Codec destinationCodec = format.equals("mp4") ? new MPEG4CompressionCodec() : new OggCompressionCodec();
        String buffer = BitrateReader.read(filename, sourceCodec);
        String result = BitrateReader.convert(buffer, destinationCodec);
        result = new AudioMixer().fix(result);
        System.out.println("=== Video Conversion Completed ===\n");
        return new File(result, filename.replace(file.getFormat(), format));
    }
}

// File class to simulate file creation after conversion
class File {
    private String data;
    private String filename;

    public File(String data, String filename) {
        this.data = data;
        this.filename = filename;
    }

    public void save() {
        System.out.println("File: " + filename + " has been saved successfully!\n");
    }
}

// Application class using the Facade
public class Application {
    public static void main(String[] args) {
        VideoConverter converter = new VideoConverter();
        File mp4 = converter.convert("funny-cats-video.ogg", "mp4");
        mp4.save();
    }
}

