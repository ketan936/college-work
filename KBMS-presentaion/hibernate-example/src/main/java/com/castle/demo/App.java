package com.castle.demo;

import java.io.IOException;
import java.net.URI;

import org.glassfish.grizzly.http.server.HttpServer;
import org.slf4j.LoggerFactory;

import com.google.inject.Injector;
import com.sun.jersey.api.container.grizzly2.GrizzlyServerFactory;
import com.sun.jersey.api.core.PackagesResourceConfig;
import com.sun.jersey.api.core.ResourceConfig;
import com.sun.jersey.core.spi.component.ioc.IoCComponentProviderFactory;
import com.sun.jersey.guice.spi.container.GuiceComponentProviderFactory;

/**
 * Hello world!
 *
 */
public class App {

	private static final URI BASE_URI = URI
			.create("http://localhost:8080/base/");
	public static final String ROOT_PATH = "helloworld";

	public static void main(String[] args) {
		try {
			System.out.println("\"Hello World\" Jersey Example App");

			// = GrizzlyHttpServerFactory.createHttpServer(BASE_URI,
			// createApp());
			ResourceConfig rc = new PackagesResourceConfig(
					"com.castle.demo.resource");
			/*
			 * final Map<String, Object> config = new HashMap<String, Object>();
			 * config.put("com.sun.jersey.api.json.POJOMappingFeature", true);
			 * rc.setPropertiesAndFeatures(config);
			 */
			/*
			 * ObjectMapper mapper = new ObjectMapper();
			 * mapper.enable(SerializationFeature.INDENT_OUTPUT);
			 * 
			 * // create JsonProvider to provide custom ObjectMapper
			 * JacksonJaxbJsonProvider provider = new JacksonJaxbJsonProvider();
			 * provider.setMapper(mapper);
			 */
			IoCComponentProviderFactory ioc = new GuiceComponentProviderFactory(
					rc, creatModule());
			final HttpServer server = GrizzlyServerFactory.createHttpServer(
					BASE_URI, rc, ioc);
			System.out
					.println(String
							.format("Application started.\nTry out %s%s\nHit enter to stop it...",
									BASE_URI, ROOT_PATH));
			System.in.read();
			server.stop();
		} catch (IOException ex) {
			LoggerFactory.getLogger(App.class.getName()).error(ex.getMessage());
		}

	}

	public static Injector creatModule() {
		return new MyApplication().getInjector();
	}
}
