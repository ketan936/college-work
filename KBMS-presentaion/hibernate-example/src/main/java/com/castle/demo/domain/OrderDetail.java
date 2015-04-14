package com.castle.demo.domain;

import java.io.Serializable;

import javax.persistence.Access;
import javax.persistence.AccessType;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
@Entity
@Table(name = "orderdetails")
@Access(AccessType.FIELD)
public class OrderDetail implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = -8671549343072476155L;

	@Id
	@ManyToOne
	@JoinColumn(name = "orderNumber")
	private Order order;
	
	@ManyToOne
	@JoinColumn(name = "productCode")
	private Product product;
	
	private int quantityOrdered;
	private double priceEach;
	private int orderLineNumber;

	public Order getOrder() {
		return order;
	}

	public void setOrder(Order order) {
		this.order = order;
	}

	public Product getProduct() {
		return product;
	}

	public void setProduct(Product product) {
		this.product = product;
	}

	public int getQuantityOrdered() {
		return quantityOrdered;
	}

	public void setQuantityOrdered(int quantityOrdered) {
		this.quantityOrdered = quantityOrdered;
	}

	public double getPriceEach() {
		return priceEach;
	}

	public void setPriceEach(double priceEach) {
		this.priceEach = priceEach;
	}

	public int getOrderLineNumber() {
		return orderLineNumber;
	}

	public void setOrderLineNumber(int orderLineNumber) {
		this.orderLineNumber = orderLineNumber;
	}

}
