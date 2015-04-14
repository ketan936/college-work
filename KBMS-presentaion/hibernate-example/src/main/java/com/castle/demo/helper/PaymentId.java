package com.castle.demo.helper;

import java.io.Serializable;

import javax.persistence.Embeddable;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;

import com.castle.demo.domain.Customer;

@Embeddable
public class PaymentId implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = -7781248376486553768L;
	@ManyToOne
	@JoinColumn(name = "customerNumber")
	private Customer customer;
	private String checkNumber;

	public Customer getCustomer() {
		return customer;
	}

	public void setCustomer(Customer customer) {
		this.customer = customer;
	}

	public String getCheckNumber() {
		return checkNumber;
	}

	public void setCheckNumber(String checkNumber) {
		this.checkNumber = checkNumber;
	}
}
