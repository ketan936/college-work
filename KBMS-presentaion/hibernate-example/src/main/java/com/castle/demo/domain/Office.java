package com.castle.demo.domain;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.Access;
import javax.persistence.AccessType;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;
@Entity
@Table(name = "offices")
@Access(AccessType.FIELD)
public class Office {
	@Id
	@Column(unique = true, nullable = false)
	private String officeCode;

    @NotEmpty(message = "City may not be null")
    @Column(nullable = false)
	private String city;
    @NotEmpty(message = "Phone may not be null")
    @Column(unique = true, nullable = false)
	private String phone;
    @NotEmpty(message = "City may not be null")
    @Column(nullable = false)
	private String addressLine1;
	private String addressLine2;
	private String state;
	@NotEmpty(message = "Country may not be null")
    @Column(nullable = false)
	private String country;
	@NotEmpty(message = "Postal Code may not be null")
    @Column(nullable = false)
	private String postalCode;
	@NotEmpty(message = "Territory may not be null")
    @Column(nullable = false)
	private String territory;
	@OneToMany(fetch = FetchType.LAZY, cascade = CascadeType.ALL, mappedBy = "office", orphanRemoval = true)
	private List<Employee> employees = new ArrayList<Employee>();

	public List<Employee> getEmployees() {
		return employees;
	}

	public void setEmployees(List<Employee> employees) {
		this.employees = employees;
	}

	public String getOfficeCode() {
		return officeCode;
	}

	public void setOfficeCode(String officeCode) {
		this.officeCode = officeCode;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getAddressLine1() {
		return addressLine1;
	}

	public void setAddressLine1(String addressLine1) {
		this.addressLine1 = addressLine1;
	}

	public String getAddressLine2() {
		return addressLine2;
	}

	public void setAddressLine2(String addressLine2) {
		this.addressLine2 = addressLine2;
	}

	public String getState() {
		return state;
	}

	public void setState(String state) {
		this.state = state;
	}

	public String getCountry() {
		return country;
	}

	public void setCountry(String country) {
		this.country = country;
	}

	public String getPostalCode() {
		return postalCode;
	}

	public void setPostalCode(String postalCode) {
		this.postalCode = postalCode;
	}

	public String getTerritory() {
		return territory;
	}

	public void setTerritory(String territory) {
		this.territory = territory;
	}

}
