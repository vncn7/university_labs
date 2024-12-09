package com.model;

import java.util.Date;
import jakarta.persistence.*;

@Entity

@Table(name = "Tpost")
public class Post {

    // Sequence generator to auto increment the ID field
    @Id
    @SequenceGenerator(name = "postSeq", sequenceName = "ZSEQ_POST_ID", allocationSize = 1, initialValue = 10)
    @GeneratedValue(generator = "postSeq") 

    // Attributes
    @Column(name = "id")
    private Long id;
    @Column(name = "text")
    private String text;
    @Column(name = "longitude")
    private Double longitude;
    @Column(name = "latitude")
    private Double latitude;
    @Column(name = "createdAt")
    private Date createdAt;
    @Column(name = "authorId")
    private Long authorId;


    // Constructors
    public Post() {
    }

    public Post(String text, double longitude, double latitude, Long userId) {
        this.text =text;
        this.longitude = longitude;
        this.latitude = latitude;
        this.authorId = userId;
        this.createdAt = new Date();
    }

    // Getters and Setters
    public Long getId() {
        return id;
    }
    public void setId(Long id) {
        this.id = id;
    }
    public String getText() {
        return text;
    }
    public void setText(String text) {
        this.text = text;
    }
    public Double getLongitude() {
        return longitude;
    }
    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }
    public Double getLatitude() {
        return latitude;
    }
    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }
    public Date getCreatedAt() {
        return createdAt;
    }
    public void setCreatedAt() {
    	 this.createdAt = new Date();
    }
    public Long getAuthorId() {
        return this.authorId;
    }
    public void setAuthorId(Long authorId) {
        this.authorId = authorId;
    }
}	 