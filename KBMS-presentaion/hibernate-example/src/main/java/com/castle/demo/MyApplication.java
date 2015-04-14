package com.castle.demo;

import javax.ws.rs.Produces;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.jaxrs.json.JacksonJsonProvider;
import com.google.inject.Guice;
import com.google.inject.Injector;
import com.google.inject.Provides;
import com.google.inject.Singleton;
import com.google.inject.servlet.GuiceServletContextListener;
import com.google.inject.servlet.ServletModule;
import com.sun.jersey.api.core.PackagesResourceConfig;
import com.sun.jersey.api.core.ResourceConfig;
import com.sun.jersey.guice.spi.container.servlet.GuiceContainer;

public class MyApplication extends GuiceServletContextListener {
	  @Override
	    protected Injector getInjector() {

	        return Guice.createInjector(new ServletModule() {

	            @Override
	            protected void configureServlets() {

	                super.configureServlets();

	                // Configuring Jersey via Guice:
	                ResourceConfig resourceConfig = new PackagesResourceConfig("com.castle.demo.resource");
	                for (Class<?> resource : resourceConfig.getClasses()) {
	                    bind(resource);
	                }
	                serve("/*").with(GuiceContainer.class);
	            }
	        }, new DemoModule()); // <-- Adding other Guice Dependency Injection Modules
	    }
	  
	  @Provides
	    @Singleton
	    @Produces
	    public JacksonJsonProvider createJacksonJsonProvider()
	    {
	        ObjectMapper objectMapper = new ObjectMapper();
	      //  objectMapper.setPropertyNamingStrategy(new MyPropertyNamingStrategy());
	        return new JacksonJsonProvider(objectMapper);
	    }

}