package com.castle.demo.resource;

import java.util.ArrayList;
import java.util.List;

import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
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
	public OfficeResource(
			CreateEntityManagerFactory createEntityManagerFactory,
			OfficeRepository officeRepository) {

		this.officeRepository = officeRepository;
	}

	@GET
	@Path("/all")
	@Produces(MediaType.APPLICATION_JSON)
	public List<Office> getOffices() {
		return officeRepository.getOffices();
	}

	@GET
	@Path("/{city}")
	@Produces(MediaType.APPLICATION_JSON)
	public List<Office> getOfficeByCity(@PathParam("city") String city) {
		return officeRepository.getOfficeByCity(city);
	}

	@GET
	public List<Office> searchOffices(
			@QueryParam("officeCode") String officeCode,
			@QueryParam("city") String city, @QueryParam("phone") String phone,
			@QueryParam("state") String state,
			@QueryParam("postalCode") String postalCode,
			@QueryParam("country") String country,
			@QueryParam("territory ") String territory) {

		return officeRepository.searchOffices(officeCode, city, phone, state,
				postalCode, country, territory);

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
	
	@DELETE
	@Path("/{id}")
	@Produces(MediaType.APPLICATION_JSON)
	public Response DeleteOfficeById(@PathParam("id") String id) {
		 officeRepository.DeleteOfficeById(id);
			return Response.status(204).build();
	}


}
