package com.castle.demo.resource;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.castle.demo.domain.Office;
import com.castle.demo.helper.CreateEntityManagerFactory;
import com.google.inject.Inject;

@Path("/office")
@Produces(MediaType.APPLICATION_JSON)
@Consumes(MediaType.APPLICATION_JSON)
public class OfficeResource {
	public static final String CLICHED_MESSAGE = "Hello World!";
	EntityManager entityManager;
	EntityManagerFactory entityManagerFactory;

	@Inject
	public OfficeResource(CreateEntityManagerFactory createEntityManagerFactory) {
		entityManagerFactory = createEntityManagerFactory
				.getEntityManagerFactory();
		entityManager = entityManagerFactory.createEntityManager();
	}

	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public List <Office> getHello() {
		List <Office>offices = entityManager.createQuery("from Office o").getResultList();
		System.out.println(offices.get(0).getCity());
		return offices;
	}

}
