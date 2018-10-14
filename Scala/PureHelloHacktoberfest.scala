import java.io.IOException
import java.time.Year

import scalaz.ioeffect._
import scalaz.ioeffect.console._

object PureHelloHacktoberfest extends SafeApp {

  override def run(args: List[String]): IO[Void, ExitStatus] =
    greetingLogic.attempt.map(_.fold(_ => 1, _ => 0)).map(ExitStatus.ExitNow(_))

  def greetingLogic: IO[IOException, Unit] =
    for {
      year <- IO.now(Year.now().getValue)
      _ <- putStrLn(s"Hello, Hacktoberfest $year!")
    } yield ()
}
