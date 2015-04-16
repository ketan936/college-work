package com.castle.demo.repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.PersistenceException;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Expression;
import javax.persistence.criteria.Predicate;
import javax.persistence.criteria.Root;
import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;

import com.castle.demo.domain.Office;
import com.castle.demo.helper.CreateEntityManagerFactory;
import com.google.inject.Inject;

public class OfficeRepository {
	EntityManager entityManager;
	EntityManagerFactory entityManagerFactory;
	private Validator validator;

	@Inject
	public OfficeRepository(
			CreateEntityManagerFactory createEntityManagerFactory) {
		entityManagerFactory = createEntityManagerFactory
				.getEntityManagerFactory();
		entityManager = entityManagerFactory.createEntityManager();
		ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
		validator = factory.getValidator();
	}

	public List<Office> getOffices() {
		List<Office> offices = entityManager.createQuery("from Office o")
				.getResultList();
		System.out.println(offices.get(0).getCity());
		return offices;
	}

	public List<Office> getOfficeByCity(String city) {
		List<Office> offices = entityManager
				.createQuery("from Office o where o.city = :city")
				.setParameter("city", city).getResultList();
		System.out.println(offices.get(0).getCity());
		return offices;
	}

	public List<String> createOffice(Office office) {
		List<String> errors = new ArrayList<String>();
		errors = validateOffice(office);
		if (errors.isEmpty()) {
			EntityTransaction txn = entityManager.getTransaction();
			txn.begin();
			try {
				entityManager.persist(office);

				txn.commit();
			} catch (PersistenceException ex) {
				txn.rollback();
				errors.add(ex.getMessage());
			}
		}

		return errors;
	}

	private List<String> validateOffice(Office office) {
		Set<ConstraintViolation<Office>> constraintViolations = validator
				.validate(office);
		List<String> errors = new ArrayList<String>();
		if (!constraintViolations.isEmpty()) {
			for (ConstraintViolation<Office> c : constraintViolations) {
				errors.add(c.getPropertyPath() + ": " + c.getMessage());
			}
		}
		return errors;
	}

	public List<Office> searchOffices(String officeCode, String city,
			String phone, String state, String postalCode, String country,
			String territory) {
		CriteriaBuilder builder = entityManager.getCriteriaBuilder();
		CriteriaQuery query = builder.createQuery();
		Root<Office> offices = query.from(Office.class);

		List<Predicate> predicates = new ArrayList<Predicate>();
		if (officeCode != null)
			predicates.add(builder.like((Expression) offices.get("officeCode"),
					officeCode));
		if (city != null)
			predicates.add(builder.like((Expression) offices.get("city"), "%"
					+ city + "%"));
		if (phone != null)
			predicates.add(builder.like((Expression) offices.get("phone"), "%"
					+ phone + "%"));
		if (state != null)
			predicates.add(builder.like((Expression) offices.get("state"), "%"
					+ state + "%"));
		if (postalCode != null)
			predicates.add(builder.like((Expression) offices.get("postalCode"),
					"%" + postalCode + "%"));
		if (country != null)
			predicates.add(builder.like((Expression) offices.get("country"),
					"%" + country + "%"));
		if (territory != null)
			predicates.add(builder.like((Expression) offices.get("territory"),
					"%" + territory + "%"));
		query.select(offices).where(predicates.toArray(new Predicate[] {}));
		return entityManager.createQuery(query).getResultList();

	}
}
