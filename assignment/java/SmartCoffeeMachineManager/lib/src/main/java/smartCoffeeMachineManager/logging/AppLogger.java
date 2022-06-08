package smartCoffeeMachineManager.logging;

import java.sql.Timestamp;
import java.time.Instant;

public final class AppLogger implements SimpleLogger {
  private static final AppLogger SINGLETON = new AppLogger();
  private static final String UNIFIER = " = ";

  private AppLogger() {}

  public static AppLogger getAppLogger() {
    return AppLogger.SINGLETON;
  }

  public void debug(final String msg) {
    System.out.println(Headers.DEBUG.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }

  public void info(final String msg) {
    System.out.println(Headers.INFO.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }

  public void warn(final String msg) {
    System.out.println(Headers.WARN.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }

  public void error(final String msg) {
    System.err.println(Headers.ERROR.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }

  public void fatal(final String msg) {
    System.out.println(Headers.FATAL.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }

  public void event(final String msg) {
    System.out.println(Headers.EVENT.get() + "[" + Timestamp.from(Instant.now()) + "]" + UNIFIER + msg);
  }
}