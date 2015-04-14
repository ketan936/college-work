package com.castle.demo;

import com.castle.demo.helper.CreateEntityManagerFactory;
import com.google.inject.AbstractModule;

public class DemoModule extends AbstractModule {

	@Override
	protected void configure() {
		bind(CreateEntityManagerFactory.class);		
	}

}
