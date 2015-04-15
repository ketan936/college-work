package com.castle.demo.repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.PersistenceException;
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

	public List<Office> getOffice() {
		List<Office> offices = entityManager.createQuery("from Office o")
				.getResultList();
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
}
