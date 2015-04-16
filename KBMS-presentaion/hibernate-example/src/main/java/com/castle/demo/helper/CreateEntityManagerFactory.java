package com.castle.demo.helper;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class CreateEntityManagerFactory {
	private  EntityManagerFactory  entityManagerFactory = Persistence.createEntityManagerFactory("test-cabinet");

	public EntityManagerFactory getEntityManagerFactory() {
		return entityManagerFactory;
	}

	public void setEntityManagerFactory(EntityManagerFactory entityManagerFactory) {
		this.entityManagerFactory = entityManagerFactory;
	}
}
