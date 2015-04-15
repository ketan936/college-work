package com.castle.demo.resource;

import java.util.ArrayList;
import java.util.List;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

import com.castle.demo.domain.Office;
import com.castle.demo.helper.CreateEntityManagerFactory;
import com.castle.demo.repository.OfficeRepository;
import com.google.inject.Inject;

@Path("/office")
@Produces(MediaType.APPLICATION_JSON)
@Consumes(MediaType.APPLICATION_JSON)
public class OfficeResource {
	public static final String CLICHED_MESSAGE = "Hello World!";
	OfficeRepository officeRepository;

	@Inject
	public OfficeResource(CreateEntityManagerFactory createEntityManagerFactory, OfficeRepository officeRepository) {
	
		this.officeRepository = officeRepository;
	}

	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public List<Office> getOffice() {
		return officeRepository.getOffice();
	}

	@POST
	@Produces(MediaType.APPLICATION_JSON)
	public Response createOffice(Office office) {
		List<String> errors = new ArrayList<String>();
		System.out.println(office.getOfficeCode());
		errors = officeRepository.createOffice(office);
		if (errors.isEmpty()) {
			return Response.status(201).entity(office).build();
		}
		return Response.status(400).entity(errors).build();
	}

}
