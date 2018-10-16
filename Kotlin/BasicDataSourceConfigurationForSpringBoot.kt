import org.springframework.boot.context.properties.ConfigurationProperties
import org.springframework.boot.jdbc.DataSourceBuilder
import org.springframework.context.annotation.Bean
import org.springframework.stereotype.Component
import javax.sql.DataSource

@Component
open class DataSources {
    // You can define datasource properties by adding e.g. mysqldatasource.driverClassName com.mysql.cj.jdbc.Driver to application.properties file
    @Bean("mysqldatasource")
    @ConfigurationProperties(prefix = "mysqldatasource")
    open fun getMySqlDataSource(): DataSource {
        return DataSourceBuilder.create().build()
    }
}
