package com.castle.demo;

import com.castle.demo.helper.CreateEntityManagerFactory;
import com.castle.demo.repository.OfficeRepository;
import com.google.inject.AbstractModule;
import com.google.inject.Singleton;

public class DemoModule extends AbstractModule {

	@Override
	protected void configure() {
		bind(CreateEntityManagerFactory.class).in(Singleton.class);
		bind(OfficeRepository.class);
	}

}
